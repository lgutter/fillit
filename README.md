# Fillit

This project is part of the 42 curriculum as was available at Codam in 2019.
The goal of the project is to take a file containing tetrominoes (tetris pieces)
as input from a text file, and calculating plus displaying the smallest
possible square containing all tetrominoes, without using rotation, and respecting the original order as much as possible.

Considering the quickly increasing complexity, and the chosen display format of
a letter for each tetromino, the maximum amount of tetrominoes is `26`.

## Looking for a challenge
I built this project with my friend Arend, and when thinking about how we would
approach this project, we were talking to other students for ideas. One of them
jokingly made the ridiculous suggestion of doing everything with bitwise operations.
After initially laughing about this we thought "why not, it sounds like a challenge!"
and thus we made the decision that would cause us headaches and sleepless nights
for weeks...

Since we only had a few months of programming experience, neither of us really
understood the purpose and power of bitwise operations, so our only plan was
"do ANYTHING we can using bitwise!". This led to some simply stupid ideas, but as
the project developed, our understand improved and so did our use of bitwise.

The final product you find here has been refactored to make some stuff at least
remotely understandable, but since I did not change any of the actual logic,
the code is still nothing to be proud of...
It is however very fast thanks to some nice tricks we were able to do thanks to our use of bitwise.

## Storing tetrominos
Every tetromino gets `32 bits` of storage. Why `32`? We need `24 bits` to store
a tetromino and its coordinates in a `16x16` map, but that is not an easily storable  and processable amount.
The next available amount is the size of an `unsigned int`: `32 bits` or `4 bytes`, so we used that.

How do store the tetromino inside these bits? Here is visualisation of the layout, per `byte`:
```
|  pos 1 & pos 2 | pos 3 & pos 4  |  X coordinate  |  Y coordinate  |
```
### Storing the shape
The first `16 bits` are used to store the shape of the tetromino, using `4 bits` for the position of every block of the tetromino within a `4x4` grid, or a chain of `16` positions. (values `0` through `15`)
This method allows us to cast the value to normal variable if needed.

### Storing the position
With a maximum of 26 tetrominoes, the largest amount of tetromino blocks we will need to handle is `26 * 4 = 104`, which would theoretically fit in an `11x11` square. But again, that does not result in an amount that is easily stored, so we allocate `1 byte` for the X coordinate, and `1 byte` for the Y coordinate, without any fancy bit manipulations.

### Why store it this way?
Storing the tetrominoes like this allows us to be very efficient with memory, but also allows us to compare tetrominoes and their position with very basic math. For example, the `16 bits` that store the shape will always hold the same value when the shape is the same. We do have to make sure all tetrominoes are always positioned in the top left of the `4x4` grid, but this is a one-time operation.

## Input parsing
A valid input file looks a little like this:
```
.#..
.#..
.##.
....

....
.##.
..#.
..#.

####
....
....
....

....
.#..
.###
....

```
Every tetromino is provided in a 4x4 block, with `#` being part of the tetromino,
and `.` being blank spots. To seperate the tetromino blocks an extra `newline` is insterted.

This blocks in this text file are then converted and stored in the format described above, shifted to the top left corner if needed, and checked for valid tetromino shapes.

## A map to solve in
As said earlier, we need to be able to handle a map size of at least `11x11` to make sure we can solve any combination of tetrominoes. We want to use a single bit per position in the map, which means we need `11 * 11 = 121` bits. As usual, this is not an easy amount to store, especially since the largest datatype we have available is `64 bits`. So we decided to use `16 unsigned shorts`, which each consist of `16 bits`, giving us a `16x16` map to work with. More than we need, but much easier to work with. Even if we only need an `8x8` square, we always work within this `16x16` grid, so IF we need to try with a larger square size, we don't have to allocate anything. (in fact, we don't use malloc at all)

## Solving

### Map size
The first step in solving is determining the smallest possible square that could theoretically fit the amount of tetrominoes. This is essentially `√(n * 4)` rounded up to the nearest integer. So for `8` tetrominoes:
```
 8 * 4 		= 32
 √32		= 5.656854249
 round up	= 6
 ```
These values were pre-calculated since they are constant, but we take a few shortcuts based on simple tetromino shapes. Here we start using the fact that each unique shape has a numerical value. For example, a square has the value `325`. You can see this in `size_exceptions` in `solver.c:33`.

### Calculating usable space
TBC

### The almighty shortcut for duplicates
TBC

### Recursive trial & error
TBC
