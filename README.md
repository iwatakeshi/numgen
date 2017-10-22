# numgen

## Usage

```
 Usage: ./numgen number [ -r random | -s shuffle <number> | -sd shuffled-descending <number> | -l list | -ld list-descending ]
```

### Generate Random Numbers

```
./numgen 100 -r >> random.txt
```

### Generate Shuffled Numbers

```
./numgen 100 -s 5 # 5 is the number of times to shuffle randomly
```

### Generate Shuffled Numbers (Descending)

```
./numgen 100 -sd 5 # 5 is the number of times to shuffle randomly
```

### Generate a List

```
./numgen 100 -l
```

### Generate a List (Descending)

```
./numgen 100 -ld
```


## Build

```shell
make
```

## Dependencies
  * [commander.h](https://github.com/iwatakeshi/commander.h)
