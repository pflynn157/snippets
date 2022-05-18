#!/bin/bash

echo "Running git pull..."

for D in ./*; do
    if [ -d "$D" ]; then
        cd "$D"
        echo ""
        echo "$D"
        
        git branch -r | grep -v '\->' | while read remote; do git branch --track "${remote#origin/}" "$remote"; done
        git fetch --all
        git pull --all
        cd ..
    fi
done

echo "Done"

