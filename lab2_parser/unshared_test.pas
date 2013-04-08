program test0017;

function r1(x : integer) : integer;
forward;

function r2(x : integer) : integer;
begin
  if x = 0 then r2 := 0
  else 
  if x div 2 = 0 then r2 := x+r1(x-1)
  else r2 := r1(x)
end;

function r1(x : integer) : integer;
begin
  if x = 1 then r1 := 1
  else
  if x div 2 <> 0 then r1 := x+r2(x-1)
  else r1 := r2(x)
end;

begin
  while not false do 
    writeint(r2(readint()))
end.
