CC=g++
CCFLAGS=-std=c++11
Imageops: Main.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Imageops main.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Testexec ImageTests.cpp Image.cpp


.cpp.o:
	$(CC) $(CCFLAGS) -c $<


main:
	./Imageops -i lenna_standard.pgm lennainvert.pgm

Testexec: ImageTests.cpp Image.cpp
	$(CC) $(CCFLAGS) -g -o Testexec ImageTests.cpp Image.cpp

test:
	./Testexec

invert:
	./Imageops -i lenna_standard.pgm lenna_invert.pgm

add:
	./Imageops -a lenna_standard.pgm lenna_hat_mask.pgm  lenna_added_hat.pgm

subtract:
	./Imageops -s lenna_standard.pgm lenna_hat_mask.pgm  lenna_subtracted_hat.pgm
threshold:
	./Imageops -t lenna_standard.pgm 160 lenna_threshold_hat.pgm

mask:
	./Imageops -l shrek_rectangular.pgm donkey_mask.pgm shrek_donkey_masked.pgm


filter:
	./Imageops -f shrek_rectangular.pgm sample_filters/motion_blur.fir shrek_motion_blurred.pgm
	./Imageops -f lenna_standard.pgm sample_filters/all_dir_edge_detect.fir lenna_alldirblurred.pgm
	./Imageops -f lenna_standard.pgm sample_filters/unity.fir lenna_unityblurred.pgm



clean:
	rm -f Imageops Testexec *.o
