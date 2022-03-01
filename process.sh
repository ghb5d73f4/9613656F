#!/bin/bash

echo "# Converting .fast file into histogram"


FASTERFILE=$1
OUTDIR=$(echo $FASTERFILE | cut -d"/" -f 2 | cut -d"." -f 1)
mkdir -pv histos/$OUTDIR

_faster2h/bin/faster2h.`hostname` --map=etc/the.map --conf=etc/the.config --input=$FASTERFILE --output=histos/$OUTDIR/
