/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:28:17 by hshakula          #+#    #+#             */
/*   Updated: 2018/09/09 13:59:21 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdbool.h>
# include <stddef.h>

struct s_dlist_node;
struct s_dlist_iter;

typedef bool			(*t_dlist_predicate)(void *data, void *context);
typedef void			(*t_dlist_iter_fnc)(void *data, void *context);

struct					s_dlist
{
	struct s_dlist_node	*begin;
	struct s_dlist_node	*end;
	int					size;
};

struct					s_dlist_iter
{
	struct s_dlist_node *node;
	struct s_dlist		*list;
};

# define DLIST_INITIALIZER ((struct s_dlist){NULL, NULL, 0})

/*
** Constructors
*/
struct s_dlist			*dlist_new(void);
struct s_dlist_node		*dlist_node_new(void *data);

/*
** Destructors
*/
void					dlist_release(
							struct s_dlist *dlist,
							void (*del)(void *data),
							bool dlist_stack_ptr);

/*
** Element access
*/
void					*dlist_front(struct s_dlist *list);
void					*dlist_back(struct s_dlist *list);
void					*dlist_element(struct s_dlist *list, size_t index);
void					*dlist_find_if(
							struct s_dlist *list,
							t_dlist_predicate predicate,
							void *ctx);

/*
** Modifiers
*/
void					*dlist_pop_back(struct s_dlist *list);
void					*dlist_pop_front(struct s_dlist *list);
void					*dlist_pop(struct s_dlist_iter *iter);

void					dlist_push_back_data(struct s_dlist *lst, void *data);
void					dlist_push_front_data(struct s_dlist *lst, void *data);
void					dlist_push_back_node(
							struct s_dlist *list,
							struct s_dlist_node *node);
void					dlist_push_front_node(
							struct s_dlist *list,
							struct s_dlist_node *node);
void					dlist_insert_data(
							struct s_dlist_iter *iter,
							void *data);

/*
** Iterator
*/
struct s_dlist_iter		dlist_iter_init(struct s_dlist *list);
extern void				dlist_next(struct s_dlist_iter *iter);
extern void				dlist_prev(struct s_dlist_iter *iter);
extern void				*dlist_iter_data(struct s_dlist_iter *iter);
void					dlist_iterate(
							struct s_dlist *list,
							t_dlist_iter_fnc iter_fnc,
							void *context);

/*
** Operations
*/
void					dlist_merge(
							struct s_dlist *dst,
							struct s_dlist *src);
void					dlist_remove_if(
							struct s_dlist *dst,
							t_dlist_predicate predicate,
							void (*del)(void *data),
							void *context);

#endif
