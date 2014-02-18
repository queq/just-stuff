module memory(load, cEnter, clk, cVirgul, enter, virgul, changeVirgul, addEnhe);

	input cEnter, cVirgul, clk, load, changeVirgul, addEnhe;
	output reg enter, virgul;

	reg tempEnter, tempVirgul;
			
	always @(posedge clk) begin 
		if (load) begin 
			tempEnter=0;
			tempVirgul=0;			
		end
		else if (cEnter==1) begin 
				tempEnter=1;
				tempVirgul=0;
			end
		else if (changeVirgul | addEnhe)begin
					tempVirgul=0;
					tempEnter=tempEnter;
			end
		else if (cVirgul==1) begin
				tempEnter=0;
				tempVirgul=1;
			end
			else begin 
				tempEnter=tempEnter;
				tempVirgul=tempVirgul;
			end
	end 
	

	always @(tempEnter or tempVirgul) begin 
		enter<=tempEnter;
		virgul<=tempVirgul;
	end

endmodule
	
	
