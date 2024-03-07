# This file is part of sway-workspace-extras
#
# Copyright (c) 2023 Thomas Himmelstoss
#
# This software is subject to the MIT license. You should have
# received a copy of the license along with this program.

{
  description = "Build sway-workspace-extras crate";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  };

  outputs = { self, nixpkgs, ... }:
    let
      supportedSystems = [ "x86_64-linux" ];

      forSupportedSystems = generator:
        let
          generateForSystem = system: generator {
            inherit system;
            pkgs = nixpkgs.legacyPackages.${system};
          };
        in
        nixpkgs.lib.genAttrs supportedSystems generateForSystem;
    in
    {
      devShells = forSupportedSystems ({ system, pkgs, ... }:
        let
          lndir = "${pkgs.xorg.lndir}/bin/lndir";
          qmkBin = "${pkgs.qmk}/bin/qmk";

          setup = pkgs.writeShellScriptBin "setup" ''
            ${qmkBin} --config-file "$PWD/qmk.ini" setup --yes
            ${lndir} -silent -ignorelinks "$PWD/keyboards" "$PWD/build/keyboards"
          '';

          build = pkgs.writeShellScriptBin "build" ''
            ${qmkBin} --config-file "$PWD/qmk.ini" compile
          '';
        in
        {
          default = pkgs.mkShell {
            packages = with pkgs; [
              qmk
              setup
              build
            ];
          };
        });

      formatter = forSupportedSystems ({ pkgs, ... }: pkgs.nixpkgs-fmt);
    };
}
