/*
 * Copyright (c) 2004, 2005  Andrei Vasiliu
 *
 *
 * This file is part of MudBot.
 *
 * MudBot is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MudBot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with MudBot; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * In addition, as a special exception, the copyright holders of Mudbot 
 * give you permission to use, copy, link, modify and
 * distribute under your own terms, binary versions of modules based
 * on MudBot.

 */

#define MODULE_ID "$Name: Release_6 $ $Id: module.h,v 3.1 2005/12/08 18:02:56 andreivasiliu Exp $"

/* Module header file, to be used with all module source files. */

#if defined( FOR_WINDOWS )
# define BUILDING_DLL
#endif

#include "header.h"

#if defined( BUILTIN_MODULE )
# define ENTRANCE( name ) void (name)( MODULE *self )
#else
# if defined( FOR_WINDOWS )
#   ifdef __cplusplus
#	  define ENTRANCE( name ) extern "C" __declspec( dllexport ) BOOL WINAPI LibMain( HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved ) { return TRUE; } \
	extern "C" __declspec(dllexport) void module_register(MODULE *self)
#	else
#	  define ENTRANCE( name ) __declspec( dllexport ) BOOL WINAPI LibMain( HINSTANCE hDLLInst, DWORD fdwReason, LPVOID lpvReserved ) { return TRUE; } \
	  __declspec( dllexport ) void module_register( MODULE *self )
#   endif
# else
#  define ENTRANCE( name ) void module_register( MODULE *self )
# endif
#endif


/*** Global functions. ***/

/* Line operators. */
void	(*prefix)( char *string );
void	(*suffix)( char *string );
void	(*replace)( char *string );
void	(*insert)( int pos, char *string );
void	(*prefixf)( char *string, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
void	(*suffixf)( char *string, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
void    (*vprefixf)( char *string, va_list args );
void    (*vsuffixf)( char *string, va_list args );
void    (*vclientff)( char *string, va_list args );
void	(*set_line)( int line );


/* Communication */
MODULE* (*get_modules)( );
void *	(*get_variable)( char *name );
void	(*DEBUG)( char *name );
void	(*debugf)( char *string, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
void	(*debugerr)( char *string );
void	(*logff)( char *type, char *string, ... ) __attribute__ ( ( format( printf, 2, 3 ) ) );
void	(*clientf)( char *string );
void	(*clientfr)( char *string );
void	(*clientff)( char *string, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
void	(*send_to_server)( char *string );
void	(*show_prompt)( );
void	(*mxp)( char *string, ... ) __attribute__ ( ( format( printf, 1, 2 ) ) );
int		(*mxp_tag)( int tag );
int		(*mxp_stag)( int tag, char *dest );
void	(*send_gmcp)(const char *szModule, const char *szData);
void	(*send_gmcp_to_server)(const char *szModule, const char *szData);

/* Utility */
#if defined( FOR_WINDOWS )
int	(*gettimeofday)( struct timeval *tv, void * );
#endif
char *	(*get_string)( char *argument, char *arg_first, int max );
int	(*cmp)( char *trigger, char *string );
void	(*extract_wildcard)( int nr, char *dest, int max );

/* Timers */ /*
TIMER *	(*get_timers)( );
int	(*get_timer)( );
void	(*add_timer)( char *name, int delay, void (*cb)( TIMER *self ), int d0, int d1, int d2 );
void	(*del_timer)( char *name ); */
/* Timers */
TIMER * (*get_timers)( );
int     (*get_timer)( );
TIMER * (*add_timer)( const char *name, double delay, void (*cb)( TIMER *self ), int d0, int d1, int d2 );
void    (*del_timer)( const char *name );
TIMER * (*get_timer_by_name)( const char *name );
double     (*get_timer_time_left)( TIMER *timer );



/* Networking */
DESCRIPTOR *(*get_descriptors)( );
int	(*mb_connect)( char *hostname, int port );
char *	(*get_connect_error)( );
void	(*add_descriptor)( DESCRIPTOR *desc );
void	(*remove_descriptor)( DESCRIPTOR *desc );
int	(*c_read)( int fd, void *buf, size_t count );
int	(*c_write)( int fd, const void *buf, size_t count );
int	(*c_close)( int fd );


#ifdef __cplusplus
#  define GET_FUNCTIONS( self ) \
	/* Line operators. */ \
	prefix = reinterpret_cast<void(*)(char *)>(self->get_func("prefix")); \
	suffix = reinterpret_cast<void(*)(char *)>(self->get_func("suffix")); \
	replace = reinterpret_cast<void(*)(char *)>(self->get_func("replace")); \
	insert = reinterpret_cast<void(*)(int, char *)>(self->get_func("insert")); \
	prefixf = reinterpret_cast<void(*)(char *, ...)>(self->get_func("prefixf")); \
	suffixf = reinterpret_cast<void(*)(char *, ...)>(self->get_func("suffixf")); \
	vprefixf = reinterpret_cast<void(*)(char *, va_list)>(self->get_func("vprefixf")); \
	vsuffixf = reinterpret_cast<void(*)(char *, va_list)>(self->get_func("vsuffixf")); \
	vclientff = reinterpret_cast<void(*)(char *, va_list)>(self->get_func("vclientff")); \
	/* Communication */ \
	get_modules = reinterpret_cast<MODULE*(*)()>(self->get_func("get_modules")); \
	get_variable = reinterpret_cast<void*(*)(char *)>(self->get_func("get_variable")); \
	DEBUG = reinterpret_cast<void(*)(char *)>(self->get_func("DEBUG")); \
	debugf = reinterpret_cast<void(*)(char *, ...)>(self->get_func("debugf")); \
	debugerr = reinterpret_cast<void(*)(char *)>(self->get_func("debugerr")); \
	logff = reinterpret_cast<void(*)(char *, char *, ...)>(self->get_func("logff")); \
	clientf = reinterpret_cast<void(*)(char *)>(self->get_func("clientf")); \
	clientfr = reinterpret_cast<void(*)(char *)>(self->get_func("clientfr")); \
	clientff = reinterpret_cast<void(*)(char *, ...)>(self->get_func("clientff")); \
	send_to_server = reinterpret_cast<void(*)(char *)>(self->get_func("send_to_server")); \
	show_prompt = reinterpret_cast<void(*)()>(self->get_func("show_prompt")); \
	mxp = reinterpret_cast<void(*)(char *, ...)>(self->get_func("mxp")); \
	mxp_tag = reinterpret_cast<int(*)(int)>(self->get_func("mxp_tag")); \
	mxp_stag = reinterpret_cast<int(*)(int, char *)>(self->get_func("mxp_stag")); \
	/* Utility */ \
	get_string = reinterpret_cast<char*(*)(char *, char *, int)>(self->get_func("get_string")); \
	cmp = reinterpret_cast<int(*)(char *, char *)>(self->get_func("cmp")); \
	/* Timers */ \
	get_timers = reinterpret_cast<TIMER*(*)()>(self->get_func("get_timers")); \
	get_timer = reinterpret_cast<int(*)()>(self->get_func("get_timer")); \
	add_timer = reinterpret_cast<TIMER*(*)(const char *, double, void(*)(TIMER*), int, int, int)>(self->get_func("add_timer")); \
	del_timer = reinterpret_cast<void(*)(const char *)>(self->get_func("del_timer")); \
	get_timer_by_name = reinterpret_cast<TIMER*(*)(const char *)>(self->get_func("get_timer_by_name")); \
	get_timer_time_left = reinterpret_cast<double(*)(TIMER*)>(self->get_func("get_timer_time_left")); \
	send_gmcp_to_server = reinterpret_cast<void(*)(const char *, const char *)>(self->get_func("send_gmcp_to_server")); \
	/* Networking */ \
	get_descriptors = reinterpret_cast<DESCRIPTOR*(*)()>(self->get_func("get_descriptors")); \
	mb_connect = reinterpret_cast<int(*)(char *, int)>(self->get_func("mb_connect")); \
	get_connect_error = reinterpret_cast<char*(*)()>(self->get_func("get_connect_error")); \
	add_descriptor = reinterpret_cast<void(*)(DESCRIPTOR*)>(self->get_func("add_descriptor")); \
	remove_descriptor = reinterpret_cast<void(*)(DESCRIPTOR*)>(self->get_func("remove_descriptor")); \
	c_read = reinterpret_cast<int(*)(int, void*, size_t)>(self->get_func("c_read")); \
	c_write = reinterpret_cast<int(*)(int, const void*, size_t)>(self->get_func("c_write")); \
	c_close = reinterpret_cast<int(*)(int)>(self->get_func("c_close"));
#else
#  define GET_FUNCTIONS( self ) \
   /* Line operators. */ \
   prefix = self->get_func( "prefix" ); \
   suffix = self->get_func( "suffix" ); \
   replace = self->get_func( "replace" ); \
   insert = self->get_func( "insert" ); \
   prefixf = self->get_func( "prefixf" ); \
   suffixf = self->get_func( "suffixf" ); \
   vprefixf = self->get_func( "vprefixf" ); \
   vsuffixf = self->get_func( "vsuffixf" ); \
   vclientff = self->get_func( "vclientff" ); \
   /* Communication */ \
   get_modules = self->get_func( "get_modules" ); \
   get_variable = self->get_func( "get_variable" ); \
   DEBUG = self->get_func( "DEBUG" ); \
   debugf = self->get_func( "debugf" ); \
   debugerr = self->get_func( "debugerr" ); \
   logff = self->get_func( "logff" ); \
   clientf = self->get_func( "clientf" ); \
   clientfr = self->get_func( "clientfr" ); \
   clientff = self->get_func( "clientff" ); \
   send_to_server = self->get_func( "send_to_server" ); \
   show_prompt = self->get_func( "show_prompt" ); \
   mxp = self->get_func( "mxp" ); \
   mxp_tag = self->get_func( "mxp_tag" ); \
   mxp_stag = self->get_func( "mxp_stag" ); \
   /* Utility */ \
   get_string = self->get_func( "get_string" ); \
   cmp = self->get_func( "cmp" ); \
   /* Timers */ \
   get_timers = self->get_func( "get_timers" ); \
   get_timer = self->get_func( "get_timer" ); \
   add_timer = self->get_func( "add_timer" ); \
   del_timer = self->get_func( "del_timer" ); \
   get_timer_by_name = self->get_func( "get_timer_by_name" ); \
   get_timer_time_left = self->get_func( "get_timer_time_left" ); \
   /* Networking */ \
   get_descriptors = self->get_func( "get_descriptors" ); \
   mb_connect = self->get_func( "mb_connect" ); \
   get_connect_error = self->get_func( "get_connect_error" ); \
   add_descriptor = self->get_func( "add_descriptor" ); \
   remove_descriptor = self->get_func( "remove_descriptor" ); \
   c_read = self->get_func( "c_read" ); \
   c_write = self->get_func( "c_write" ); \
   c_close = self->get_func( "c_close" );
#endif