# C/C++ PDFTables.com API example

This example must be linked to `libcurl`. It uploads a file called
`example.pdf` and writes the result to `stdout`.

Before compiling you need to edit `pdftables.c` to replace
`YOUR_API_KEY` with an API key that you've obtained from [the
PDFTables.com API page](https://pdftables.com/API).

## Compiling

On Linux you can install the cURL development libraries with your
package manager.

Debian, Ubuntu: `sudo apt-get install libcurl4-openssl-dev`

Redhat, CentOS: `sudo yum install libcurl-devel`

You can compile it with GCC like so:

`gcc -o pdftables pdftables.c -lcurl`

or simply run `make`.
