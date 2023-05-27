/*
 * Filename: gluethread_op.h
 * Description: link list operations for glue based doubly-link list
 * Date: 26/05/2023
 */

#ifndef __GLUETHREAD_OP__
#define __GLUETHREAD_OP__

typedef struct glue {

	struct glue *right;
	struct glue *left;
}glue_t;

#endif
