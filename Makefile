all:
	@echo "Este makefile solo borra los archivos objeto y ejecutables. No compila nada. Para compilar, ver el archivo fuente de cada ejemplo."

clean:
	rm -Rf *.o *.a *.so *.exe a.out 
	rm -Rf 06*/*.o 06*/*.a 06*/*.so 06*/*.exe 06*/a.out
	rm -Rf 07*/*.o 07*/*.a 07*/*.so 07*/*.exe 07*/a.out
	rm -Rf 08*/*.o 08*/*.a 08*/*.so 08*/*.exe 08*/a.out
