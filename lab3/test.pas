program whatever;

type
	r = record
		c,e: record d: integer end
	end;
  s = record
    s1: record
      s2: record
        s3: boolean;
        s4: integer
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
  var5: record
          s1: record
            s2: record
              s3: boolean;
              s4: integer;
              s5: array[1..10] of string
            end
          end
        end;

function foo1(a, a : integer) : r;  
begin
   {a := 0}
end;

function foo3() : integer;
begin
  {a := foo3(1, 2, 3);}
end;

begin
  var1 := false * var3;
  if int1+int2 then a := 0; 
  if false then var1 := false;
  for a := 0 to 10 do begin for b:= 0 to var2 do begin end end;
  var4.s1.s2.s3 := var4.s1.s2.s4.s6.s7;
  var1 := foo1(false, var1);
  var5 := var1;
end.
