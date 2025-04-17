# MY LS (EPITECH PROJECT)

## DISCLAIMER

**_This project was designed to be done in C but I decided to do it C++. Therefore all the requirements of the project might not be met, especially the functions, libraries and the coding style._** 

## Description

MY LS is a project to recreate the Unix `ls` command, which lists directory contents. This version supports various options such as `-a`, `-l`, `-R`, `-d`, `-r`, and `-t`, and can handle multiple files or directories as arguments.

## Usage

To compile the program, use the provided Makefile:

```sh
make
```

This will generate the `my_ls` binary. To run the program, use the following command:

```sh
./my_ls [OPTIONS] [FILE...]
```

Options can be combined and provided in any order. For example:

```sh
./my_ls -l -t
./my_ls -lt
./my_ls -l -r file1 file2
```

If no files or directories are specified, `my_ls` will list the contents of the current directory.

## Examples

Here are some examples of using `my_ls`:

- List the contents of the current directory:

```sh
./my_ls
```

- List the contents with detailed information:

```sh
./my_ls -l
```

- List all files, including hidden ones, in reverse order:

```sh
./my_ls -a -r
```

- List the contents of multiple directories:

```sh
./my_ls -l /dev /usr/sbin
```

- List files with time-based sorting:

```sh
./my_ls -t
```

## Bonus Features (I MIGHT DO IT IN THE FUTURE)

Implementing the following features will be considered as bonus points:

- Handling column formatting without the `-l` option.
- Sorting and coloring the output.
- Supporting additional options such as `-u`, `-F`, `-g`, `-f`.

## Lore

The project includes a creative backstory about a character named Aki who discovers ancient technology in a post-apocalyptic world. This lore sets the context for the project, emphasizing the rediscovery of lost knowledge through coding.

## For More Details

For a detailed description of the project, including the full lore and specifications, refer to the [B-PSU-100_my_ls.pdf](https://github.com/user-attachments/files/19797728/B-PSU-100_my_ls.pdf)
).
