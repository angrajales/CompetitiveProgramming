{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,v,j: longint;
  ans: int64;
  a: array [0..9] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
  begin
    v:=i mod 9;
    if v = 0 then v:=9;
    inc(a[v]);
  end;
  ans:=0;
  for i:=1 to 9 do
    for j:=1 to 9 do
    begin
      v:=(i*j) mod 9;
      if v = 0 then v:=9;
      ans:=ans+a[i]*a[j]*a[v];
    end;
  for i:=1 to n do ans:=ans-n div i;
  writeln(ans);
  close(input);
  close(output);
end.