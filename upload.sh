#!/bin/bash

git add -u
git add data/*.setup
git add DAQ/*.root
git add histos/*/*.h1.txt

git commit -m "[auto] from `hostname` at `date`"

git push
