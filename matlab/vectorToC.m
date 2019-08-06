%   Converts a matlab vector into a C header for Arduino
%
%   This function takes three arguments: a vector, a string naming
%   the variable and the resulting header file and the numerical
%   type of the array elements. Since this is meant for the Arduino
%   PROGMEM is used to write this as a constant to ROM.
%
%   This code is part of the AutomationShield hardware and software
%   ecosystem. Visit http://www.automationshield.com for more
%   details. This code is licensed under a Creative Commons
%   Attribution-NonCommercial 4.0 International License.
%
%   Created by:      Gergely Tak�cs.
%   Last updated by: Gergely Tak�cs
%   Last update on:  6.8.2019.

function vectorToC(var,varName,numtype)

if min(size(var))~=1
    error('Function defined for vectors only.')
    return
else
    
filehandle=fopen([varName,'.h'],'wt');

fprintf(filehandle,['#ifndef ',varName,'_H\n']);
fprintf(filehandle,['#define ',varName,'_H\n']);
fprintf(filehandle,'\n');
fprintf(filehandle,['#include <avr/pgmspace.h>']);
fprintf(filehandle,'\n');
fprintf(filehandle,['#define ',varName,'_length %d\n'],length(var));
fprintf(filehandle,['const PROGMEM ',numtype,' ',varName,'[',varName,'_length]={%.9g'],var(1));
fprintf(filehandle,',\n %.9g',var(2:end));
fprintf(filehandle,'};\n');
fprintf(filehandle,'#endif\n');
fclose(filehandle);

end


