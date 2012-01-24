package main

import (
	"bufio"
	"bytes"
	"flag"
	"fmt"
	"io"
	"os"
)

var fileName string
var height int
var width int

func main() {
	flag.StringVar(&fileName, "text", "text", "Use a valid filename")
	flag.IntVar(&height, "height", 5, "Use a valid height")
	flag.IntVar(&width, "width", 20, "Use a valid width")
	flag.Parse()
	if fileName == "" {
		panic("File not found")
	}
	if width < 1 {
		panic("Invalid width")
	}
	if height < 1 {
		panic("Invalid height")
	}

	file, err := os.Open(fileName)
	if err != nil {
		panic(err)
	}

	reader := bufio.NewReader(file)
	buffer := bytes.NewBuffer(make([]byte, 1024))
	pos := 0
	for {
		c, err := reader.ReadByte()
		if err == io.EOF {
			break
		}
		if c != '\'' && c != ' ' && c != '"' {
			buffer.WriteByte(c)
			pos++
			if pos%width == 0 {
				buffer.WriteByte('\n')
			}
			if pos % (width * height) == 0 {
				buffer.WriteByte('\n')
			}
		}

	}
	fmt.Println(buffer)

}
