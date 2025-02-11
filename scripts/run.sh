#!/bin/bash -x
#
# Run various DELPHI example programs
#
# Choose the executable by creating a link
#
# ln -s exampleXX.sh run.sh
#
# Syntax:
#    exampleXX.sh [--input NICKNAME] [--mc] [--output OUTPUT]
#
# Dietrich Liko <Dietrich.Liko@oeaw.ac.at>

set -e

SCRIPT_PATH="$(realpath -s "${BASH_SOURCE[-1]}")"
SCRIPT_DIR="$(dirname "$SCRIPT_PATH")"
SCRIPT_NAME="$(basename "$SCRIPT_PATH" .sh)"
BINARY=${SCRIPT_DIR}/../build/${SCRIPT_NAME}/${SCRIPT_NAME}
WORK_DIR="/afs/cern.ch/work/${USER:0:1}/$USER/${SCRIPT_NAME}_$$"

info() {
    echo "$(date "+%Y-%M-%d %H:%m:%S") INFO $@" >&2
}

error() {
    echo "$(date "+%Y-%M-%d %H:%m:%S") ERROR $@" >&2
}

if [ ! -e "$BINARY" ]; then
    error "$SCRIPT_NAME does not exist."
    exit 1
fi

NICKNAME="short95_d2/c10"
OPTIONS=()
while [ $# -gt 0 ]
do
    case "$1" in
        -h|--help)
            echo "Usage: $SCRIPT_NAME.sh [--input NICKNAME] [--mc] [--output OUTPUT]" >&2
            exit 0
            ;;
        --mc)
            OPTIONS+=("--mc")
            shift
            ;;
        --output)
            OPTIONS+=("--output" "$2")
            shift 2
            ;;
        --input)
            NICKNAME="$2"
            shift 2
            ;;
        *)
            echo "ERROR: Unexpected argument $1" >&2
            exit 1
            ;;
    esac
done

mkdir -p "$WORK_DIR"
cd "$WORK_DIR" || exit 1
info "Workdir $WORK_DIR"

cat - >PDLINPUT <<EOF
FATMEN = $NICKNAME
EOF

info "Running $NAME on $NICKNAME ..."
"$BINARY" "${OPTIONS[@]}"

