--- src/gallium/state_trackers/xvmc/tests/xvmc_bench.c.orig	2013-10-05 05:59:22.000000000 +0200
+++ src/gallium/state_trackers/xvmc/tests/xvmc_bench.c	2014-03-02 13:21:35.000000000 +0100
@@ -28,8 +28,8 @@
 #include <assert.h>
 #include <stdio.h>
 #include <string.h>
-#include <error.h>
 #include <sys/time.h>
+#include <unistd.h>
 #include "testlib.h"
 
 #define MACROBLOCK_WIDTH		16
@@ -144,23 +144,10 @@
 	}
 
 	if (fail)
-		error
-		(
-			1, 0,
-			"Bad argument.\n"
-			"\n"
-			"Usage: %s [options]\n"
-			"\t-iw <width>\tInput width\n"
-			"\t-ih <height>\tInput height\n"
-			"\t-ow <width>\tOutput width\n"
-			"\t-oh <height>\tOutput height\n"
-			"\t-p <pipeline>\tPipeline to test\n"
-			"\t-mb <mb type>\tMacroBlock types to use\n"
-			"\t-r <reps>\tRepetitions\n\n"
-			"\tPipeline steps: mc,csc,swap\n"
-			"\tMB types: i,p,b\n",
-			argv[0]
-		);
+	{
+		printf ("error happened\n");
+		exit(1);
+	}
 
 	if (config->output_width == 0)
 		config->output_width = config->input_width;
@@ -214,7 +201,8 @@
 	))
 	{
 		XCloseDisplay(display);
-		error(1, 0, "Error, unable to find a good port.\n");
+		printf("Error, unable to find a good port.\n");
+		exit(1);
 	}
 
 	if (is_overlay)
