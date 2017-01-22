[![Build Status](https://travis-ci.org/AcePeak/AceCmakeBase.svg?branch=master)](https://travis-ci.org/AcePeak/AceCmakeBase)
[![Coverage Status](https://coveralls.io/repos/github/AcePeak/AceCmakeBase/badge.svg?branch=master)](https://coveralls.io/github/AcePeak/AceCmakeBase?branch=master)
[![Code Health](https://landscape.io/github/AcePeak/AceCmakeBase/master/landscape.svg?style=flat)](https://landscape.io/github/AcePeak/AceCmakeBase/master)

AceCmakeBase sample project
===============================

This is an base project including travis-ci and coveralls indicator supports by default.

# Instructions

 * Build your project with [gcov support](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html)
 * Run tests
 * Run `coveralls`

## Environment variables

`cpp-coveralls` recognizes the following environment variables:
- `COVERALLS_REPO_TOKEN`
- `COVERALLS_ENDPOINT`
- `COVERALLS_PARALLEL`


## Usage:

```
$ coveralls -h
usage: coveralls [-h] [--verbose] [--dryrun] [--gcov FILE]
                 [--gcov-options GCOV_OPTS] [-r DIR] [-b DIR] [-e DIR|FILE]
                 [-i DIR|FILE] [-E REGEXP] [-x EXT] [-y FILE] [-n] [-t TOKEN]
                 [--encodings ENCODINGS [ENCODINGS ...]] [--dump [FILE]]

optional arguments:
  -h, --help            show this help message and exit
  --verbose             print verbose messages
  --dryrun              run coveralls without uploading report
  --gcov FILE           set the location of gcov
  --gcov-options GCOV_OPTS
                        set the options given to gcov
  -r DIR, --root DIR    set the root directory
  -b DIR, --build-root DIR
                        set the directory from which gcov will be called; by
                        default gcov is run in the directory of the .o files;
                        however the paths of the sources are often relative to
                        the directory from which the compiler was run and
                        these relative paths are saved in the .o file; when
                        this happens, gcov needs to run in the same directory
                        as the compiler in order to find the source files
  -e DIR|FILE, --exclude DIR|FILE
                        set exclude file or directory
  -i DIR|FILE, --include DIR|FILE
                        set include file or directory
  -E REGEXP, --exclude-pattern REGEXP
                        set exclude file/directory pattern
  -x EXT, --extension EXT
                        set extension of files to process
  -y FILE, --coveralls-yaml FILE
                        coveralls yaml file name (default: .coveralls.yml)
  -n, --no-gcov         do not run gcov
  -t TOKEN, --repo-token TOKEN, --repo_token TOKEN
                        set the repo_token of this project, alternatively you
                        can set the environmental variable
                        COVERALLS_REPO_TOKEN
  --encodings ENCODINGS [ENCODINGS ...]
                        source encodings to try in order of preference
                        (default: ['utf-8', 'latin-1'])
  --dump [FILE]         dump JSON payload to a file
```

## Example `.travis.yml`

### Linux

Install `cpp-coveralls` with `pip`, add *gcov* to your compilation option, compile, run your test and send the result to http://coveralls.io :
```
language: cpp
compiler:
  - gcc
before_install:
  - pip install --user cpp-coveralls
script:
  - ./configure --enable-gcov && make && make check
after_success:
  - coveralls --exclude lib --exclude tests --gcov-options '\-lp'
```

### OS X

*Python* on *OS X* can be a bit of a hassle so you need to install to set up your custom environment:

```
language: objective-c
compiler:
  - gcc
before_install:
  - brew update
  - brew install pyenv
  - eval "$(pyenv init -)"
  - pyenv install 2.7.6
  - pyenv global 2.7.6
  - pyenv rehash
  - pip install cpp-coveralls
  - pyenv rehash
script:
  - ./configure --enable-gcov && make && make check
after_success:
  - coveralls --exclude lib --exclude tests --gcov-options '\-lp'
```