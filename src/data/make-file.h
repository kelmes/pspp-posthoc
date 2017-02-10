/* PSPP - a program for statistical analysis.
   Copyright (C) 2004, 2010 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef MAKE_FILE_H
#define MAKE_FILE_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>

struct file_handle;

/* Prepares to atomically replace a (potentially) existing file
   by a new file., by creating a temporary file with the given
   PERMISSIONS bits.

   Special files are an exception: they are not atomically
   replaced but simply opened for writing.

   If successful, stores a stream for it opened according to MODE (which should be
   "w" or "wb") in *FP.  Returns a ticket that can be used to
   commit or abort the file replacement.  If neither action has
   yet been taken, program termination via signal will cause
   all resources to be released.  The return value must not be
   explicitly freed.

   The caller is responsible for closing *FP */

struct replace_file *replace_file_start (const struct file_handle *fh,
                                         const char *mode, mode_t permissions,
                                         FILE **fp);

/* Commits or aborts the replacement of a (potentially) existing
   file by a new file, using the ticket returned by
   replace_file_start.  Returns success. */
bool replace_file_commit (struct replace_file *);
bool replace_file_abort (struct replace_file *);

#endif /* make-file.h */
