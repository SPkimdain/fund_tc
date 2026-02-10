#!/bin/bash
set -e

ORIGDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKDIR=$(mktemp -d)

trap "rm -rf $WORKDIR" 0 INT QUIT ABRT PIPE TERM
cd $WORKDIR

zcat $ORIGDIR/foo.fa.gz > foo.fa
$1 --runThreadN 1 --runMode genomeGenerate \
  --genomeDir . --genomeSAindexNbases 8 \
  --genomeFastaFiles foo.fa \
  --sjdbGTFfile  $ORIGDIR/foo.gtf

zcat $ORIGDIR/reads.fastq.gz > reads.fastq
$1 --runThreadN 1 --genomeDir . \
  --readFilesIn reads.fastq

[ -s Aligned.out.sam ]
