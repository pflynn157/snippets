#!/bin/bash

# To send:
#scp ./pihole.sh pi@raspberrypi.local://home/pi

pihole -b \
    reddit.com \
    cnbc.com \
    www.cnbc.com \
    wcnc.com \
    youtube.com \
    cnn.com \
    fox46.com \
    foxnews.com \
    news.google.com \
    theguardian.com \
    zdnet.com \
    lkml.org \
    aconsciousrethink.com \
    highlysensitiverefuge.com \
    introvertdear.com \
    mail.google.com \
    protonmail.com \
    torproject.org \
    wikipedia.org \
    politico.com \
    theintercept.com
    
pihole --wild \
    reddit.com \
    cnbc.com \
    www.cnbc.com \
    wcnc.com \
    cnn.com \
    fox46.com \
    foxnews.com \
    theguardian.com \
    zdnet.com \
    lkml.org \
    aconsciousrethink.com \
    highlysensitiverefuge.com \
    introvertdear.com \
    torproject.org \
    wikipedia.org \
    politico.com \
    theintercept.com

