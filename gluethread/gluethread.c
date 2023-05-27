/*
 * Filename: gluethread_op.c
 * Description: link list operations for glue based doubly-link list
 * Date: 26/05/2023
 */

#include <stdlib.h>
#include "gluethread.h"

void init_gthread(glue_t *gluethread){

	gluethread->right = NULL;
	gluethread->left = NULL;
}

void add_after_gthread(glue_t *current_glue, glue_t *new_glue) {

	if(!current_glue->right) {
		current_glue->right = new_glue;
		new_glue->left = current_glue;
		return;
	}

	glue_t *temp = current_glue->right;
	current_glue->right = new_glue;
	new_glue->left = current_glue;
	new_glue->right = temp;
	temp->left = new_glue;
	return;
}

void add_before_gthread(glue_t *current_glue, glue_t *new_glue) {

	if(!current_glue->left) {
		current_glue->left = new_glue;
		new_glue->right = current_glue;
		return;
	}

	glue_t *temp = current_glue->left;
        current_glue->left = new_glue;
        new_glue->right = current_glue;
        new_glue->left = temp;
        temp->right = new_glue;
        return;
}

void remove_gthread(glue_t *current_glue) {

	if(!current_glue->left) {
		if(current_glue->right) {
			current_glue->right->left = NULL;
			current_glue->left = NULL;
			return;
		}
		return;
	}
	if(!current_glue->right) {
		current_glue->left->right = NULL;
		current_glue->left = NULL;
                return;
	}

	current_glue->left->right = current_glue->right->left;
	current_glue->right->left = current_glue->left->right;
	current_glue->right = NULL;
	current_glue->left = NULL;
	return;
}

void delete_gthread(glue_t *base_glue) {

	glue_t *current_glue = NULL;

	for(current_glue = base_glue; current_glue != NULL; current_glue = base_glue->right ) {
		remove_gthread(current_glue);
	}
	return;
}

void add_last_gthread(glue_t *base_glue, glue_t *new_glue) {

	glue_t *temp = base_glue;

	while(base_glue->right) {
		base_glue = base_glue->right;
	}
	add_after_gthread(base_glue, new_glue);
	return;
}

unsigned int get_count_gthread(glue_t *base_glue) {

	unsigned int count=0;
	glue_t *temp = base_glue;

        while(base_glue) {
                base_glue = base_glue->right;
		count++;
        }
        return count;
}
