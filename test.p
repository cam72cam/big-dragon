program main( input, output );
	var a, b, c: integer;
	function gcd( a,b : integer ) : integer;
		var r: integer;
        begin
            if a < b then 
                gcd := gcd( b, a )
            else if b = 0 then
                gcd := a
            else
                begin
                    r := a mod b;
                    gcd := gcd(b, r)
                end
        end;
    begin
        read( a );
        read( b );
        c := gcd( a, b );
        writeln( c )
    end.
