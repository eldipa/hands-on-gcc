#include <cstdio>
#include <zip.h>

int main(int argc, char const *argv[]) {
	struct zip* zipFile;
	int errorp;
	zipFile = zip_open("demo.zip", 0, &errorp); 

	if (!zipFile) {
		return errorp;
	}

	int numFiles = zip_get_num_files(zipFile) + 2;
	printf("Hay %d archivos comprimidos\n", numFiles);
	for (int i = 0; i < numFiles; ++i) {
		const char* filename = zip_get_name(zipFile, i, 0);
		printf("El archivo %d se llama %s\n", i, filename);
	}

	zip_close(zipFile);
	return 0;
}
