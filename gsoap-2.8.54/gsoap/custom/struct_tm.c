/*
	struct_tm.c

	Custom serializer for <time.h> struct tm as xsd:dateTime

	See struct_tm.h for documentation.

	Compile this file and link it with your code.

gSOAP XML Web services tools
Copyright (C) 2000-2015, Robert van Engelen, Genivia Inc., All Rights Reserved.
This part of the software is released under ONE of the following licenses:
GPL, the gSOAP public license, OR Genivia's license for commercial use.
--------------------------------------------------------------------------------
gSOAP public license.

The contents of this file are subject to the gSOAP Public License Version 1.3
(the "License"); you may not use this file except in compliance with the
License. You may obtain a copy of the License at
http://www.cs.fsu.edu/~engelen/soaplicense.html
Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the License.

The Initial Developer of the Original Code is Robert A. van Engelen.
Copyright (C) 2000-2015, Robert van Engelen, Genivia, Inc., All Rights Reserved.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

/* soapH.h generated by soapcpp2 from .h file containing #import "struct_tm.h" */
#include "soapH.h"

SOAP_FMAC3 void SOAP_FMAC4 soap_default_xsd__dateTime(struct soap *soap, struct tm *a)
{
  (void)soap;
  memset((void*)a, 0, sizeof(struct tm));
}

SOAP_FMAC3 void SOAP_FMAC4 soap_serialize_xsd__dateTime(struct soap *soap, struct tm const *a)
{
  (void)soap; (void)a;
}

SOAP_FMAC3 const char * SOAP_FMAC4 soap_xsd__dateTime2s(struct soap *soap, const struct tm a)
{
  strftime(soap->tmpbuf, sizeof(soap->tmpbuf), "%Y-%m-%dT%H:%M:%SZ", &a);
  return soap->tmpbuf;
}

SOAP_FMAC3 int SOAP_FMAC4 soap_out_xsd__dateTime(struct soap *soap, const char *tag, int id, const struct tm *a, const char *type)
{
  if (soap_element_begin_out(soap, tag, soap_embedded_id(soap, id, a, SOAP_TYPE_xsd__dateTime), type)
   || soap_string_out(soap, soap_xsd__dateTime2s(soap, *a), 0))
    return soap->error;
  return soap_element_end_out(soap, tag);
}

SOAP_FMAC3 int SOAP_FMAC4 soap_s2xsd__dateTime(struct soap *soap, const char *s, struct tm *a)
{
  memset((void*)a, 0, sizeof(struct tm));
  if (s)
  {
    char *t;
    unsigned long d;
    d = soap_strtoul(s, &t, 10);
    if (*t == '-')
    {
      /* YYYY-MM-DD */
      a->tm_year = (int)d;
      a->tm_mon = (int)soap_strtoul(t + 1, &t, 10);
      a->tm_mday = (int)soap_strtoul(t + 1, &t, 10);
    }
    else if (!(soap->mode & SOAP_XML_STRICT))
    {
      /* YYYYMMDD */
      a->tm_year = (int)(d / 10000);
      a->tm_mon = (int)(d / 100 % 100);
      a->tm_mday = (int)(d % 100);
    }
    else
      return soap->error = SOAP_TYPE;
    if (*t == 'T' || ((*t == 't' || *t == ' ') && !(soap->mode & SOAP_XML_STRICT)))
    {
      d = soap_strtoul(t + 1, &t, 10);
      if (*t == ':')
      {
	/* Thh:mm:ss */
	a->tm_hour = (int)d;
	a->tm_min = (int)soap_strtoul(t + 1, &t, 10);
	a->tm_sec = (int)soap_strtoul(t + 1, &t, 10);
      }
      else if (!(soap->mode & SOAP_XML_STRICT))
      {
	/* Thhmmss */
        a->tm_hour = (int)(d / 10000);
	a->tm_min = (int)(d / 100 % 100);
	a->tm_sec = (int)(d % 100);
      }
      else
	return soap->error = SOAP_TYPE;
    }
    if (a->tm_year == 1)
      a->tm_year = 70;
    else
      a->tm_year -= 1900;
    a->tm_mon--;
    if (*t == '.')
    {
      for (t++; *t; t++)
        if (*t < '0' || *t > '9')
          break;
    }
    if (*t == ' ' && !(soap->mode & SOAP_XML_STRICT))
      t++;
    if (*t)
    {
#ifndef WITH_NOZONE
      if (*t == '+' || *t == '-')
      {
	int h, m;
	m = (int)soap_strtol(t, &t, 10);
        if (*t == ':')
        {
	  /* +hh:mm */
	  h = m;
	  m = (int)soap_strtol(t + 1, &t, 10);
          if (h < 0)
            m = -m;
        }
        else if (!(soap->mode & SOAP_XML_STRICT))
	{
	  /* +hhmm */
          h = m / 100;
          m = m % 100;
        }
        else
	{
	  /* +hh */
          h = m;
	  m = 0;
        }
	if (*t)
	  return soap->error = SOAP_TYPE;
        a->tm_min -= m;
        a->tm_hour -= h;
        /* put hour and min in range */
        a->tm_hour += a->tm_min / 60;
        a->tm_min %= 60;
        if (a->tm_min < 0)
        {
	  a->tm_min += 60;
          a->tm_hour--;
        }
        a->tm_mday += a->tm_hour / 24;
        a->tm_hour %= 24;
        if (a->tm_hour < 0)
        {
	  a->tm_hour += 24;
          a->tm_mday--;
        }
        /* note: day of the month may be out of range, timegm() handles it */
      }
      else if (*t != 'Z')
	return soap->error = SOAP_TYPE;
#endif
    }
    else /* no UTC or timezone, so assume we got a localtime */
      a->tm_isdst = -1;
  }
  return soap->error;
}

SOAP_FMAC3 struct tm * SOAP_FMAC4 soap_in_xsd__dateTime(struct soap *soap, const char *tag, struct tm *a, const char *type)
{
  if (soap_element_begin_in(soap, tag, 0, NULL))
    return NULL;
  if (*soap->type
   && soap_match_att(soap, soap->type, type)
   && soap_match_att(soap, soap->type, ":dateTime"))
  {
    soap->error = SOAP_TYPE;
    soap_revert(soap);
    return NULL;
  }
  a = (struct tm*)soap_id_enter(soap, soap->id, a, SOAP_TYPE_xsd__dateTime, sizeof(struct tm), NULL, NULL, NULL, NULL);
  if (*soap->href)
    a = (struct tm*)soap_id_forward(soap, soap->href, a, 0, SOAP_TYPE_xsd__dateTime, 0, sizeof(struct tm), 0, NULL, NULL);
  else if (a)
  {
    if (soap_s2xsd__dateTime(soap, soap_value(soap), a))
      return NULL;
  }
  if (soap->body && soap_element_end_in(soap, tag))
    return NULL;
  return a;
}
