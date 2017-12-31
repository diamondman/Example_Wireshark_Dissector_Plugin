# About

There are several good tutorials on how to write plugins for
wireshark, but I found most of them did not satisfactorily describe
how to compile and load the plugin. This repository exists to fill in
the missing pieces and act as a starting point for those other
tutorials.

# Other tutorials to look into.

* [{wireshark_source}/doc/README.plugins](https://github.com/wireshark/wireshark/blob/master/doc/README.plugins)
* [Wireshark Chapter 9.2. Adding a basic dissector](https://www.wireshark.org/docs/wsdg_html_chunked/ChDissectAdd.html)

# Building

## Building on Debian/Ubuntu (Linux)

```bash
sudo apt install wireshark wireshark-dev cmake
cd ${ThisProjectDir}
mkdir build
cd build
cmake ..
make
make install
```

## Building on Mac OSX

```bash
brew install wireshark --with-headers
cd ${ThisProjectDir}
mkdir build
cd build
cmake ..
make
make install
```

## Building on Windows

I have not tried this. It will require a plugin.rc file and maybe some
additional configuration.

# Wireshark Plug-in loading

Wireshark loads all plugin files (.so or .dll depending on the
platform) from the global and personal plugin folders. These folders
can be found by opening wireshark, opening the About Wireshark window,
clicking on Folders, and looking at the path next to 'Global Plugins'
and 'Personal Plugins'.

I have read that launching wireshark from a directory will cause
wireshark to load plugins from that directory, but I have not seen
this work.

More details about the plugin folders can be found [here](https://www.wireshark.org/docs/wsug_html_chunked/ChPluginFolders.html).

# Changing the Plugin install directory

The default plugin install location of this project is `~/.config/wireshark/plugins`. If you wish to install your plugin to a different location, you can do so by specifying the CMAKE_INSTALL_LIBDIR parameter to cmake on the command line.

```bash
#.....
cd build
cmake -DCMAKE_INSTALL_LIBDIR=/new/path/for/plugins ..
make
#.....
````

# Understanding the CMake structure.

The cmake folder in the root of this repository contains several files
named `FindXXX.cmake` where XXX is a library name. These files know
how to search for `XXXConfig.cmake` which contains details about the
particular installation of the library in the system. It is common to
put the `FindXXX.cmake` files, as well as other short helper scripts,
in your repository. It is not considered good practice to include a
`XXXConfig.cmake` in your repository.
