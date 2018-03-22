#!/bin/bash

grep --color=always --exclude-dir cmake-build-debug/ --exclude-dir extern/ --exclude-dir .git $@ .
