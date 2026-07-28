module direct_mapped_cache #(
    parameter ADDR_WIDTH  = 16,
    parameter DATA_WIDTH  = 32,
    parameter INDEX_WIDTH = 4
)(
    input  logic                     clk,
    input  logic                     rst,

    input  logic                     req_valid,//Indicates that the CPU has issued a request.
    input  logic                     req_type,      // 0 = READ, 1 = WRITE

    input  logic [ADDR_WIDTH-1:0]    address,
    input  logic [DATA_WIDTH-1:0]    data_in,  //The data being written during a write request.

    output logic [DATA_WIDTH-1:0]    data_out,//Returns data to the CPU on a successful read
    output logic                     hit,//Indicates whether the requested address exists in the cache.
    output logic                     ready
);

   
    // Parameters
    

    localparam OFFSET_WIDTH = 2;//32bit->1 word -> 4 bytes-> 2^2= 4-> 2 bits recquired 
    localparam TAG_WIDTH    = ADDR_WIDTH - INDEX_WIDTH - OFFSET_WIDTH;//16 - 4 - 2 = 10 bits
    localparam NUM_LINES    = 1 << INDEX_WIDTH;//2^4 = 16

    
    // Cache Memory
    

    logic [DATA_WIDTH-1:0] data_array  [0:NUM_LINES-1];
    logic [TAG_WIDTH-1:0]  tag_array   [0:NUM_LINES-1];
    logic                  valid_array [0:NUM_LINES-1];

    // Address Decode
  

    logic [TAG_WIDTH-1:0] tag;
    logic [INDEX_WIDTH-1:0] index;
    logic [OFFSET_WIDTH-1:0] offset;

    assign tag    = address[ADDR_WIDTH-1 : INDEX_WIDTH+OFFSET_WIDTH];
    assign index  = address[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    assign offset = address[OFFSET_WIDTH-1:0];

    
    // Hit Detection
  

    logic cache_hit;

    assign cache_hit =
            valid_array[index] &&
            (tag_array[index] == tag);

    
    // FSM
    

    typedef enum logic [2:0]
    {
        IDLE, //wait for req
        CHECK,//req1-> hit?
        READ_HIT,//req0
        WRITE_HIT,//req1
        MISS//not in cache, Read miss returns no data. Write miss allocates a new cache line
    } state_t;

    state_t state,next_state;

    //first always ff-> store stage, mid always comb-> calculate next state -> second always ff perform cache operation
    // State Register-> current state
    

    always_ff @(posedge clk or posedge rst)
    begin
        if(rst)
            state <= IDLE;
        else
            state <= next_state;
    end

    // Next State Logic
   

    always_comb
    begin

        next_state = state;

        case(state)

            IDLE:
            begin
                if(req_valid)
                    next_state = CHECK;
            end

            CHECK:
            begin
                if(cache_hit)
                begin
                    if(req_type)
                        next_state = WRITE_HIT;
                    else
                        next_state = READ_HIT;
                end
                else
                    next_state = MISS;
            end

            READ_HIT:
                next_state = IDLE;

            WRITE_HIT:
                next_state = IDLE;

            MISS:
                next_state = IDLE;

            default:
                next_state = IDLE;

        endcase

    end

   
    // Cache Operations
   

    integer i;

    always_ff @(posedge clk or posedge rst)
    begin

        if(rst)
        begin

            for(i=0;i<NUM_LINES;i=i+1)
            begin
                data_array[i]  <= '0;
                tag_array[i]   <= '0;
                valid_array[i] <= 1'b0;
            end

            data_out <= '0;
            hit      <= 1'b0;
            ready    <= 1'b0;

        end
        else
        begin

          
            // Default Outputs
           

            hit   <= 1'b0;
            ready <= 1'b0;

            case(state)

              
                // Read Hit
              

                READ_HIT:
                begin
                    data_out <= data_array[index];
                    hit      <= 1'b1;
                    ready    <= 1'b1;
                end

              
                // Write Hit
                

                WRITE_HIT:
                begin
                    data_array[index] <= data_in;

                    hit   <= 1'b1;
                    ready <= 1'b1;
                end

              
                // Cache Miss
              

                MISS:
                begin

                    hit   <= 1'b0;
                    ready <= 1'b1;

                    // READ MISS
                    if(req_type == 1'b0)
                    begin
                        data_out <= '0;
                    end

                    // WRITE MISS
                    else
                    begin
                        data_array[index]  <= data_in;
                        tag_array[index]   <= tag;
                        valid_array[index] <= 1'b1;
                    end

                end

            endcase

        end

    end

endmodule