#poisson_image_editing : poisson_image_editing.cc
#	g++ -c -ggdb `pkg-config opencv --cflags --libs` poisson_image_editing.cc -o poisson_image_editing.o
make_mask : make_mask.cc
	g++ -ggdb `pkg-config opencv --cflags --libs` make_mask.cc -o make_mask 
resize_image : resize_image.cc
	g++ -ggdb `pkg-config opencv --cflags --libs` resize_image.cc -o resize_image 
clean:
	rm -rf make_mask make_mask*M resize_image resize_image*M


