.PHONY: clean

pdftables:
	gcc -o pdftables pdftables.c -lcurl

clean:
	rm pdftables
