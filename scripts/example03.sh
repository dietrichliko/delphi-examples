#!/bin/bash -x

NICKNAME=${1:-"short95_d2/C10"}

SCRIPT_PATH="$(realpath "${BASH_SOURCE[-1]}")"
SCRIPT_DIR="$(dirname "$SCRIPT_PATH")"
SCRIPT_NAME="$(basename "$SCRIPT_PATH" .sh)"


WORK_DIR="/afs/cern.ch/work/${USER:0:1}/$USER/${SCRIPT_NAME}_$$"
mkdir -p "$WORK_DIR"
cd "$WORK_DIR" || exit 1

cat - >PDLINPUT <<EOF
FATMEN = $NICKNAME
EOF

"$SCRIPT_DIR/../build_$SCRIPT_NAME/$SCRIPT_NAME"
