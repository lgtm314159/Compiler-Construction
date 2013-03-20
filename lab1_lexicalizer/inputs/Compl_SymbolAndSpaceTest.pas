{
	Symbol and Space Test
	Error on variable "l","m","n", "o"
}
	
program symbol_test;

type
  int = integer;

var
  i : integer;
  j : integer;
  k : integer;
  l : integer;
  m : integer;
  n : integer;
  o : integer; 	

begin
  i := 5;
  j := 10;
  k := i + j;
  l := k + $;
  m := k <= !;
  n := 5 * @;
  o := # - #; 	
end.

