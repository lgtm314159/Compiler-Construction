{ 
	Error Free Test
}

program errorfree_test;
type
	r = record
		a,b : integer;
		c   : string
	end;
	y = array[1..10] of integer;
	s = string;
var
	z : s;

function foo1(a : integer) : r; 
begin
   a := 0
end;


function foo3(a, b : integer) : s; forward;

begin
	z := foo3(3) { Recursive Call }
end.
