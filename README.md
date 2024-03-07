# QMK Configuration

This repository contains my personal QMK configuration. It consists of a
keymap for a Kyria v3 split keyboard. 

# Kyria Keymap

The keymap is based on the [NeoQwertz](https://www.neo-layout.org/Layouts/neoqwertz/)
layout, but layers 5 and 6 are not implemented. Therefore, it consists of the
following five layers:

1. QWERTZ base layer
2. Symbol layer (Neo layer 3)
3. Navigation layer (left side of Neo layer 4)
4. Number layer (right side of Neo layer 4)
5. Function key layer

There are some notable derivations from NeoQwertz:

* The insert key on the navigation layer was replaced by a space key

This keymap assumes the OS keyboard layout is set to German.

# Development

The repository is not a full fork of the upstream QMK repository. Instead
the upstream repository is cloned through the `qmk setup` command. The
custom keymap is then linked into the checkout using the `lndir` command.

## Setup

The Nix development shell contains a script to perform the initial QMK
repository checkout and linking of the customized keymap:

    setup

## Building

There is another script to trigger the build of the firmware:

    build
