# gum-opencv-test

Quick test that opencv is working on your gumstix or anywhere I suppose, but
really just to test OE installation of the proper tools.


## Warning

I don't particularly like the way the OE developers chose to package the opencv 
stuff. I use a modified opencv recipe so that opencv-dev installs both headers 
and libraries. I have no use for any opencv code samples on a gumstix.

So here's my one-liner patch to the recipes/opencv/opencv_svn.bb recipe

### make-opencv-dev-useful.patch

	diff --git a/recipes/opencv/opencv_svn.bb b/recipes/opencv/opencv_svn.bb
	index b8134a4..62e122d 100644
	--- a/recipes/opencv/opencv_svn.bb
	+++ b/recipes/opencv/opencv_svn.bb
	@@ -55,7 +55,7 @@ python populate_packages_prepend () {
	 FILES_${PN} = ""
	 FILES_${PN}-apps = "${bindir}/* ${datadir}/opencv/"
	 FILES_${PN}-dbg += "${libdir}/.debug"
	-FILES_${PN}-dev = "${includedir} ${libdir}/pkgconfig"
	+FILES_${PN}-dev = "${includedir} ${libdir}/pkgconfig ${libdir}/libopencv*"
	 
	 ALLOW_EMPTY_${PN} = "1"

You don't have to use it. I think the official way to get development headers and
libraries is to install both opencv-dev and opencv-samples, but I'm not sure. 
(TODO: check on this)


## Install

If you are building an image for your gumstix, then add these two packages to
your image recipe. This is assuming the modified opencv-dev patch above.

	task-native-sdk
	opencv-dev

Without my patch, add opencv-samples too. (I think)

There is a minimal based image called opencv-image.bb in the oe-stuff directory
of this project you can use for a quick test.

Copy that to your recipes/images/ directory and build it for your rootfs.


## Test

When you boot your gumstix with the rootfs containing the sdk and opencv-dev
packages you should be able to use the makefile included to build a quick
test app.

Copy the gum-opencv-test project to your gumstix or if you install git, clone
it directly. 

Then

	root@overo:~/gum-opencv-test# make
	gcc -Wall -Wno-unused-function `pkg-config opencv --cflags` `pkg-config opencv --libs` flip.c -o flip

	root@overo:~/gum-opencv-test# ./flip
	Loading image
	Flipping image
	Saving flipped image

The result is the opencv.jpg flipped horizontally and saved as flipped.jpg




