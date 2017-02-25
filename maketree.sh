#!/bin/bash
tree -L 3 > tree.txt
find . -mindepth 2 -maxdepth 2 -type d -not -path '*/\.*' | wc -l | sed 's/.*/Total & problems./' >> tree.txt
