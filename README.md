[![Build Status](https://travis-ci.org/AcePeak/AceCmakeBase.svg?branch=master)](https://travis-ci.org/AcePeak/AceCmakeBase)
[![Coverage Status](https://coveralls.io/repos/github/AcePeak/AceCmakeBase/badge.svg?branch=master)](https://coveralls.io/github/AcePeak/AceCmakeBase?branch=master)

AceCmakeBase sample project
===============================

This is an base project including travis-ci and coveralls indicator supports by default.

Usage
-----

```bash
$ git clone https://github.com/AcePeak/AceCmakeBase
$ cd coveralls-cmake-example
$ git submodule update --init
$ mkdir build && cd build
$ cmake -DCOVERALLS=ON -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ make coveralls 	##may not work in local machine build.
```

FAQ

Q: After I've setup everything according to the guide I get this message when running the script on Travis-ci:

{"message":"Couldn't find a repository matching this job.","error":true}
What is wrong?

A: Not sure why this happens sometimes. But one thing to try is to try the solution mentioned in this ticket: https://github.com/lemurheavy/coveralls-public/issues/279

That is, adding this to your .travis.yml before cmake is run

- export COVERALLS_SERVICE_NAME=travis-ci
- export COVERALLS_REPO_TOKEN=abc12345