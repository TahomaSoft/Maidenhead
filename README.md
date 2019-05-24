# Repository Description

This repository contains a program which converts regular lontitude and latitude coordinates to the Maidenhead Locator System. It is written in C.

# What is the Maidenhead Locator System?

The Maidenhead Locator System is a grid system which divides the earth in fields, squares, subsquares and extended subsquares. The extended subsquares could be again split in extended subsquares.

![Example of Grid System](https://upload.wikimedia.org/wikipedia/commons/1/1d/Maidenhead_grid_over_Europe.svg)

If we want the Maidenhead Locator string of Londen, it would be:

| Field | Square | Subsquare | Ext. Subsq. |
| ----- | ------ | --------- | ----------- |
| IO    | 91     | xm        | 02          |

# Setup

## Cloning

Assuming you already have the Git CLI installed

```sh
$ git clone https://github.com/ellipticcurv3/Maidenhead.git
```

## Compiling

This step makes the build scripts executable and builds the application.

```sh
$ cd ./Maidenhead
$ chmod +x ./build.sh
$ ./build.sh
```

## Testing

I added a test script to test if the executable file is doing it's job correctly. It could be used after building.

```sh
$ chmod +x ./test.sh
$ ./test.sh
```

## Executing

Executing the program is simple. Use coordinates in decimal format.

```sh
$ ./maidenhead.o <latitude> <longitude>
```

# TODO

Someone please help me configuring `automake`, so that people could use `make`. Feel free to send me a pull request.