#!/bin/bash

BACKUP="/media/patrick/Backup/laptop"

if [[ ! -d $BACKUP ]] ; then
    mkdir $BACKUP
fi

if [[ ! -z $1 ]] ; then
    if [[ $1 == "--no-pull" ]] ; then
        if [[ -f $HOME/Projects/update-git.sh ]] ; then
            LAST_DIR=`pwd`
            cd $HOME/Projects
            ./update-git.sh
            cd $LAST_DIR
        fi
    fi
fi

rsync -av --delete $HOME/Archive $BACKUP
rsync -av --delete "$HOME/Blog Code" $BACKUP
#rsync -av --delete "$HOME/Code Snippets" $BACKUP
rsync -av --delete $HOME/Desktop $BACKUP
rsync -av --delete $HOME/Documents $BACKUP
#rsync -av --delete $HOME/Downloads $BACKUP
rsync -av --delete "$HOME/Family Pics" $BACKUP
rsync -av --delete $HOME/Music $BACKUP
rsync -av --delete "$HOME/Operating Systems" $BACKUP
rsync -av --delete $HOME/Pictures $BACKUP
rsync -av --delete $HOME/Projects $BACKUP
rsync -av --delete $HOME/Records $BACKUP
rsync -av --delete $HOME/Videos $BACKUP
rsync -av --delete $HOME/website $BACKUP

echo ""
echo "Done"


