# numgen

## Usage

```
 Usage: ./numgen number [ -r random | -s shuffle [number] | -l list | -ld list-descending ]
```

### Generate Random Numbers

```
./numgen 100 -r >> random.txt
```

### Generate Shuffled Numbers

```
./numgen 100 -s 5 >> shuffled.txt # 5 is the number of times to shuffle randomly
```

### Generate a List

```
./numgen 100 -l >> list.txt 
```

### Generate a List (Descending)

```
./numgen 100 -ld >> list.txt 
```


## Build

```shell
make
```

## Clean

```shell
make clean
```

## Dependencies
  * [commander.h](https://github.com/iwatakeshi/commander.h)
