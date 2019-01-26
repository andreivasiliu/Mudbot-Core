<<<<<<< HEAD
/* Blank Module, that does absolutely nothing. */

#define BLANK_ID "$Name: Release_6 $ $Id: blank.c,v 3.1 2005/12/08 18:02:51 andreivasiliu Exp $"

/* #include <...> */
=======
#define I_BLANK_ID "$Name:  $ $Id: i_blank.c,v 1.0 "__DATE__" blank Exp $"
>>>>>>> Added two new timer functions: get_timer_by_name and get_timer_time_left.

#include "module.h"


<<<<<<< HEAD
int blank_version_major = 0;
int blank_version_minor = 0;

char *blank_id = BLANK_ID "\r\n" HEADER_ID "\r\n" MODULE_ID "\r\n";



/* Here we register our functions. */

void blank_init_data( );


ENTRANCE( blank_module_register )
{
   self->name = strdup( "BlankMod" );
   self->version_major = blank_version_major;
   self->version_minor = blank_version_minor;
   self->id = blank_id;
   
   self->init_data = blank_init_data;
   self->process_server_line_prefix = NULL;
   self->process_server_line_suffix = NULL;
   self->process_server_prompt_informative = NULL;
   self->process_server_prompt_action = NULL;
   self->process_client_command = NULL;
   self->process_client_aliases = NULL;
   self->build_custom_prompt = NULL;
   
   self->main_loop = NULL;
   self->update_descriptors = NULL;
   self->update_modules = NULL;
   self->update_timers = NULL;
   self->debugf = NULL;
=======
// Globals

int blank_version_major = 1;
int blank_version_minor = 0;

char *i_blank_id = I_BLANK_ID "\r\n" HEADER_ID "\r\n" MODULE_ID "\r\n";

/* Here we register our functions. */

void i_blank_module_init_data( );
void i_blank_module_unload( );
void i_blank_process_server_line( LINE *line );
void i_blank_process_server_prompt( LINE *line );
int  i_blank_process_client_aliases( char *cmd );
void i_blank_process_server_gmcp( char *gmcp );


ENTRANCE( i_blank_module_register )
{
   self->name = _strdup( "Blank" );
   self->version_major = blank_version_major;
   self->version_minor = blank_version_minor;
   self->id = i_blank_id;

   self->init_data = i_blank_module_init_data;
   self->unload = i_blank_module_unload;
   self->process_server_line = i_blank_process_server_line;
   self->process_server_prompt = i_blank_process_server_prompt;
   self->process_server_gmcp = i_blank_process_server_gmcp;
   self->process_client_aliases = i_blank_process_client_aliases;
>>>>>>> Added two new timer functions: get_timer_by_name and get_timer_time_left.
   
   GET_FUNCTIONS( self );
}

<<<<<<< HEAD


void blank_init_data( )
{
   
   
}

/* Called before unloading. *
void blank_unload( )
{
   
   
}
*/

/* Not yet called anywhere, but reserved for copyright notices. *
void blank_show_notice( )
{
   
   
}
*/

/* Called before every normal line.
 * Args: colorless_line = String with all color codes stripped.
 *       colorful_line = String with all non-printable characters stripped.
 *       raw_line = String containing the data as it came from the server.
 *
void blank_process_server_line_prefix( char *colorless_line, char *colorful_line, char *raw_line )
{
   
   
}
*/

/* Called after every normal line.
 * Args: Check above.
 *
void blank_process_server_line_suffix( char *colorless_line, char *colorful_line, char *raw_line )
{
   
   
}
*/

/* Called before every prompt.
 * Args: line = String with all colors stripped.
 *       rawline = String with everything in it.
 *
void blank_process_server_prompt_informative( char *line, char *rawline )
{
   
   
}
*/

/* Called after every prompt.
 * Args: rawline = String with everything in it.
 *
void blank_process_server_prompt_action( char *rawline )
{
   
   
}
*/

/* Called for every client command that begins with `.
 * Args: cmd = The command, including the initial symbol.
 * Returns: 1 = Command is known.
 *          0 = Command is unknown, pass it to the other modules.
 *
int blank_process_client_command( char *cmd )
{
   
   
}
*/

/* Called for every client command.
 * Args: cmd = The command string.
 * Returns: 1 = Don't send it further to the server.
 *          0 = Check it with other modules, and send it to the server.
 *
int blank_process_client_aliases( char *cmd )
{
   
   
}
*/

/* Called before a prompt, but after process_prompt_informative.
 * Returns: NULL = Use the normal prompt.
 *          string = Use this instead of the normal prompt.
 *
char *blank_build_custom_prompt( )
{
   
   
}
*/

=======
int i_blank_process_client_aliases( char *szLine )
{
	return 0;
}

void i_blank_process_server_gmcp( char *gmcp)
{

}

void i_blank_process_server_line( LINE *line )
{
	print_buffer_prefix();

	// process the raw text
	process_line_raw( line->raw_line);

	// process the regular text
	process_line( line->line);
}

void i_blank_process_server_prompt( LINE *line )
{
	print_buffer_prefix();
	// process prompt triggers
	process_prompt( line->line);
	print_buffer();
}

void i_blank_module_init_data( )
{

}

void i_blank_module_unload()
{

}

// main function
void process_line( char *line )
{
	DEBUG("i_blank_process_line");
}

void process_line_raw( char *line )
{
	DEBUG("i_blank_process_line");
}

// process prompt
void process_prompt( char *line )
{
	DEBUG("i_blank_process_line");
}
>>>>>>> Added two new timer functions: get_timer_by_name and get_timer_time_left.
