program whatever;

type
	r = record
		c,e: record d: integer end
	end;
  s = record
    s1: record
      s2: record
        s3: boolean
      end
    end
  end;
var
  var1: r;
	var2: array[1..10] of integer;
	var3: array[1..10] of string;
  a: boolean;
  var4: s;
  int1: integer;
  int2: integer;

function foo1(a, a : integer) : r;  
begin
   {a := 0}
end;

function foo3() : integer;
begin
  {a := foo3(1, 2, 3);}
end;

begin
  {var1 := false * var3;}
  {if int1+int2 then a := 0; 
  if false then var1 := false;}
  var4.s1.s2.s3 := 0;
  var4.s1.s2.s3 := 0;
end.
