#include "/scratch/riccardo.gandolfi/work/pulp/pulp-sdk/rtos/pulpos/pulp_hal/include/hal/dma/idma_v2.h"
#include "DeeployBasicMath.h"
#include "DeeployPULPMath.h"
#include "bsp/ram.h"
#include "pmsis.h"
#include "pulp_core.h"
#include "pulp_nn_kernels.h"
#include "stdint.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Network.h"

int8_t *DeeployNetwork_MEMORYARENA_L1;
int8_t *DeeployNetwork_MEMORYARENA_L2;
int8_t *DeeployNetwork_input_0;
int8_t *DeeployNetwork_input_1;
int32_t *DeeployNetwork_output_0;

static PI_L2 uint8_t DeeployNetwork_TILING_REPLACED_L1_Add_0_numTiles[2] = {0, 1};

static PI_L1 int32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1_offset[1] = {0};

static PI_L1 uint32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1size[1] = {125};

static PI_L1 int32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2_offset[1] = {0};

static PI_L1 uint32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2size[1] = {125};

static PI_L1 int32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_out_offset[1] = {0};

static PI_L1 uint32_t DeeployNetwork_TILING_REPLACED_L1_Add_0_data_outsize[1] = {500};

void *DeeployNetwork_inputs[2];
void *DeeployNetwork_outputs[1];
extern struct pi_device cluster_dev;
typedef struct {
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2;
  int32_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out;
} Add_0_tiling_closure_args_t;

static void Add_0_tiling_closure(void *Add_0_tiling_closure_args) {
  // CLOSURE ARG CAST
  Add_0_tiling_closure_args_t *args = (Add_0_tiling_closure_args_t *)Add_0_tiling_closure_args;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2;
  int32_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out;

  // CLOSURE FUNCTION CALL

  // Add (Name: Add_0, Op: Add)
  BEGIN_SINGLE_CORE
  for (uint32_t i = 0; i < 125; i++) {
    DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out[i] =
        DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1[i] + DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2[i] + 0;
  }
  END_SINGLE_CORE

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2;
  int32_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out;
} Add_0_cluster_fork_args_t;

static void Add_0_cluster_fork(void *Add_0_cluster_fork_args) {
  // CLOSURE ARG CAST
  Add_0_cluster_fork_args_t *args = (Add_0_cluster_fork_args_t *)Add_0_cluster_fork_args;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1;
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2;
  int32_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out = args->DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out;

  // CLOSURE FUNCTION CALL
  Add_0_tiling_closure_args_t DeeployNetwork_Add_0_tiling_closure_args =
      (Add_0_tiling_closure_args_t){.DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1,
                                    .DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2,
                                    .DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out};

  // Add_0_tiling_closure CLOSURE CALL
  Add_0_tiling_closure(&DeeployNetwork_Add_0_tiling_closure_args);

  pi_cl_team_barrier();

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_input_0;
  int8_t *DeeployNetwork_input_1;
  int32_t *DeeployNetwork_output_0;
  uint8_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr;
} Add_0_closure_args_t;

static void Add_0_closure(void *Add_0_closure_args) {
  // CLOSURE ARG CAST
  Add_0_closure_args_t *args = (Add_0_closure_args_t *)Add_0_closure_args;
  int8_t *DeeployNetwork_input_0 = args->DeeployNetwork_input_0;
  int8_t *DeeployNetwork_input_1 = args->DeeployNetwork_input_1;
  int32_t *DeeployNetwork_output_0 = args->DeeployNetwork_output_0;
  uint8_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = args->DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 500);
  int8_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 625);
  int32_t *DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out = (int32_t *)((char *)DeeployNetwork_MEMORYARENA_L1 + 0);
  int32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1_offset_ref = (int32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1_offset;
  uint32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1size_ref = (uint32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1size;
  int32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2_offset_ref = (int32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2_offset;
  uint32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2size_ref = (uint32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2size;
  int32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_out_offset_ref = (int32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_out_offset;
  uint32_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_data_outsize_ref = (uint32_t *)DeeployNetwork_TILING_REPLACED_L1_Add_0_data_outsize;
  DMA_copy DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out =
      (DMA_copy){.dst = DeeployNetwork_output_0, .src = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out, .size = 500, .direction = 0};
  DMA_copy DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2 =
      (DMA_copy){.src = DeeployNetwork_input_1, .dst = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2, .size = 125, .direction = 1};
  DMA_copy DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1 =
      (DMA_copy){.src = DeeployNetwork_input_0, .dst = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1, .size = 125, .direction = 1};

  int32_t dma_channel = pulp_cl_idma_get_id_to_L2();

  DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1.tid = dma_channel;

  DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2.tid = dma_channel;

  DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out.tid = dma_channel;

  // TILING LOOP
  for (int TILING_I = DeeployNetwork_TILING_REPLACED_L1_Add_0_numTiles[*DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr];
       TILING_I < DeeployNetwork_TILING_REPLACED_L1_Add_0_numTiles[(*DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr) + 1]; TILING_I++) {

    // UPDATE DMA STRUCT DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1.src =
        ((char *)DeeployNetwork_input_0) + DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1_offset_ref[TILING_I];
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1.size = DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_1size_ref[TILING_I];

    // UPDATE DMA STRUCT DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2.src =
        ((char *)DeeployNetwork_input_1) + DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2_offset_ref[TILING_I];
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2.size = DeeployNetwork_TILING_REPLACED_L1_Add_0_data_in_2size_ref[TILING_I];

    // IMPORT TILE DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 from DeeployNetwork_input_0
    pulp_cl_idma_transfer(DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_1);

    // IMPORT TILE DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 from DeeployNetwork_input_1
    pulp_cl_idma_transfer(DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_in_2);

    Add_0_cluster_fork_args_t DeeployNetwork_Add_0_cluster_fork_args =
        (Add_0_cluster_fork_args_t){.DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1 = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_1,
                                    .DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2 = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_in_2,
                                    .DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out = DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out};

    pi_cl_team_fork(NUM_CORES, (void *)Add_0_cluster_fork, &DeeployNetwork_Add_0_cluster_fork_args);

    // UPDATE DMA STRUCT DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out.dst =
        ((char *)DeeployNetwork_output_0) + DeeployNetwork_TILING_REPLACED_L1_Add_0_data_out_offset_ref[TILING_I];
    DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out.size = DeeployNetwork_TILING_REPLACED_L1_Add_0_data_outsize_ref[TILING_I];

    // IMPORT TILE DeeployNetwork_TILING_REPLACED_Add_0_L1_ref_data_out from DeeployNetwork_output_0
    pulp_cl_idma_transfer(DeeployNetwork_TILING_REPLACED_L1__DMA_Add_0_data_out);

    // CLOSE TILING LOOP
  }
  *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr += 1;

  // CLOSURE ARG WRITEBACK
}

typedef struct {
  int8_t *DeeployNetwork_input_0;
  int8_t *DeeployNetwork_input_1;
  int32_t *DeeployNetwork_output_0;
  uint8_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr;
} Add_0_closure_L3_args_t;

static void Add_0_closure_L3(void *Add_0_closure_L3_args) {
  // CLOSURE ARG CAST
  Add_0_closure_L3_args_t *args = (Add_0_closure_L3_args_t *)Add_0_closure_L3_args;
  int8_t *DeeployNetwork_input_0 = args->DeeployNetwork_input_0;
  int8_t *DeeployNetwork_input_1 = args->DeeployNetwork_input_1;
  int32_t *DeeployNetwork_output_0 = args->DeeployNetwork_output_0;
  uint8_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = args->DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr;

  // CLOSURE FUNCTION CALL
  Add_0_closure_args_t DeeployNetwork_Add_0_closure_args =
      (Add_0_closure_args_t){.DeeployNetwork_input_0 = DeeployNetwork_input_0,
                             .DeeployNetwork_input_1 = DeeployNetwork_input_1,
                             .DeeployNetwork_output_0 = DeeployNetwork_output_0,
                             .DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr};

  // Add_0_closure CLOSURE CALL
  Add_0_closure(&DeeployNetwork_Add_0_closure_args);

  // CLOSURE ARG WRITEBACK
}

void RunNetwork(__attribute__((unused)) uint32_t core_id, __attribute__((unused)) uint32_t numThreads) {

  uint8_t bu_DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = 0;
  uint8_t *DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = &bu_DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr;
  Add_0_closure_L3_args_t DeeployNetwork_Add_0_closure_L3_args =
      (Add_0_closure_L3_args_t){.DeeployNetwork_input_0 = DeeployNetwork_input_0,
                                .DeeployNetwork_input_1 = DeeployNetwork_input_1,
                                .DeeployNetwork_output_0 = DeeployNetwork_output_0,
                                .DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr = DeeployNetwork_TILING_REPLACED_L1_Add_0_tileIdxPtr};

  // Add_0_closure_L3 CLOSURE CALL
  Add_0_closure_L3(&DeeployNetwork_Add_0_closure_L3_args);
}

void InitNetwork(__attribute__((unused)) uint32_t core_id, __attribute__((unused)) uint32_t numThreads) {

  DeeployNetwork_MEMORYARENA_L1 = (int8_t *)pmsis_l1_malloc(sizeof(int8_t) * 750);

  DeeployNetwork_MEMORYARENA_L2 = (int8_t *)pi_l2_malloc(sizeof(int8_t) * 750);

  DeeployNetwork_input_0 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 500);
  DeeployNetwork_input_1 = (int8_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 625);
  DeeployNetwork_output_0 = (int32_t *)((char *)DeeployNetwork_MEMORYARENA_L2 + 0);
  DeeployNetwork_inputs[0] = (void *)DeeployNetwork_input_0;
  DeeployNetwork_inputs[1] = (void *)DeeployNetwork_input_1;
  DeeployNetwork_outputs[0] = (void *)DeeployNetwork_output_0;


  printf ("DeeployNetwork_MEMORYARENA_L1: 0x%8x \n", DeeployNetwork_MEMORYARENA_L1);
  printf ("DeeployNetwork_MEMORYARENA_L2: 0x%8x \n", DeeployNetwork_MEMORYARENA_L2);
  printf ("DeeployNetwork_input_0: 0x%8x \n", DeeployNetwork_input_0);
  printf ("DeeployNetwork_input_1: 0x%8x \n", DeeployNetwork_input_1);
  printf ("DeeployNetwork_output_0: 0x%8x \n", DeeployNetwork_output_0);
  printf ("DeeployNetwork_inputs[0]: 0x%8x \n", DeeployNetwork_inputs[0]);
  printf ("DeeployNetwork_inputs[1]: 0x%8x \n", DeeployNetwork_inputs[1]);
  printf ("DeeployNetwork_outputs[0]: 0x%8x \n", DeeployNetwork_outputs[0]);
}
