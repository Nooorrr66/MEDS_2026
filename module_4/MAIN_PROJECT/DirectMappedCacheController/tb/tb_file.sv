`timescale 1ns/1ps

module cache_tb;

    parameter ADDR_WIDTH  = 16;
    parameter DATA_WIDTH  = 32;
    parameter INDEX_WIDTH = 4;

    logic clk;
    logic rst;
    logic req_valid;
    logic req_type;          // 0 = READ, 1 = WRITE
    logic [ADDR_WIDTH-1:0] address;
    logic [DATA_WIDTH-1:0] data_in;

    logic [DATA_WIDTH-1:0] data_out;
    logic hit;
    logic ready;

    
    // DUT
    
    direct_mapped_cache #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .INDEX_WIDTH(INDEX_WIDTH)
    ) DUT (
        .clk(clk),
        .rst(rst),
        .req_valid(req_valid),
        .req_type(req_type),
        .address(address),
        .data_in(data_in),
        .data_out(data_out),
        .hit(hit),
        .ready(ready)
    );

   
    // Clock
    

    initial clk = 0;
    always #5 clk = ~clk;

    //wave
	initial begin
        $dumpfile("cache_waveform.vcd");
        $dumpvars(0, cache_tb);
    end
    // Write Task
   

    task write_cache(
        input [15:0] addr,
        input [31:0] data
    );
    begin
        @(posedge clk);
        req_valid = 1;
        req_type  = 1;
        address   = addr;
        data_in   = data;

        @(posedge clk);
        req_valid = 0;
//wait for fsm to complete
        wait(ready);
        @(posedge clk);
    end
    endtask

   
    // Read Task
    

    task read_cache(
        input [15:0] addr
    );
    begin
        @(posedge clk);
        req_valid = 1;
        req_type  = 0;
        address   = addr;

        @(posedge clk);
        req_valid = 0;

        wait(ready);

        @(posedge clk);
    end
    endtask

   
    // Test Sequence
    

    initial
    begin

        rst = 1;
        req_valid = 0;
        req_type = 0;
        address = 0;
        data_in = 0;

        repeat(2) @(posedge clk);
        rst = 0;

        
        // TEST 1
        

        $display("\nTEST 1 : Write to Empty Cache Line");

        write_cache(16'h0010,32'hAAAA5555);

        if(DUT.valid_array[4] &&
           DUT.data_array[4]==32'hAAAA5555)
            $display("PASS");
        else
            $display("FAIL");

       
        // TEST 2
       

         $display("\nTEST 2 : Read Same Address");

        read_cache(16'h0010);

        if(hit && data_out==32'hAAAA5555)
            $display("PASS");
        else
            $display("FAIL");

        // TEST 3
       

          $display("\nTEST 3 : Read Empty Line");

        read_cache(16'h0020);

        if(!hit)
            $display("PASS");
        else
            $display("FAIL");

        
        // TEST 4
       

		$display("\nTEST 4 : Same Index Different Tag");

        // Same index = 4
        // Different tag

        write_cache(16'h0410,32'h12345678);

        read_cache(16'h0010);

        if(!hit)
            $display("PASS");
        else
            $display("FAIL");

        
        // TEST 5
        

        $display("\nTEST 5 : Read Updated Address");

        read_cache(16'h0410);

        if(hit && data_out==32'h12345678)
            $display("PASS");
        else
            $display("FAIL");

        $display("\nAll tests completed.");

        #20;
        $finish;

    end

endmodule