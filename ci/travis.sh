#!/bin/sh

install_utility () {
    sudo apt-get update -qq && sudo apt-get install -qq devscripts build-essential equivs python-software-properties
}

build_handystats () {
  git clone --recursive https://github.com/shindo/handystats.git -b master
  cd handystats
  yes | sudo mk-build-deps -i
  yes | debuild -uc -us
  cd .. && sudo dpkg -i *.deb || sudo apt-get install -f && rm -rf handystats
}

make_env () {
    echo "Install utility packages..."
    install_utility
    echo "Build & install packages..."
    build_handystats
    echo "Waiting..."
    sleep 1
}

make_env
