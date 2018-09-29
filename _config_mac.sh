#!/bin/bash
set -e

CMAKE=cmake
VERBOSE_CMAKE="OFF"
PROJECT_TYPE="Unix Makefiles"

for var in "$@"
do
    if [[ $var == "v" ]]; then
        VERBOSE_CMAKE="ON"
    elif [[ $var == "x" ]]; then
        PROJECT_TYPE="Xcode"
    fi
done

if [[ "$0" = /* ]]; then
    FULL_PATH=$(dirname "$0")
else
    FULL_PATH=$(dirname `find "$PWD/$0"`)
fi

if [ "$PROJECT_TYPE" != "Xcode" ]; then
	BUILD_DIR="buildUnix"
else
	BUILD_DIR="buildXcode"
fi

FULL_BUILD_PATH=$FULL_PATH/$BUILD_DIR

mkdir -p $FULL_BUILD_PATH

cd $FULL_BUILD_PATH

$CMAKE -G "$PROJECT_TYPE" \
    -DFULL_PATH="$FULL_PATH" \
    -DCMAKE_VERBOSE="$VERBOSE_CMAKE" \
    ..
