#define RETENTION_PERIOD = 21
/* The length of an epoch in minutes */
#define EPOCH_LENGTH  15
/* Number of epochs in a day */
#define NUM_EPOCHS_PER_DAY  1440 // EPOCH_LENGTH
/* Length of EphID in bytes */
#define LENGTH_EPHID  16
/* Seconds in a UNIX Epoch day */
#define SECONDS_PER_DAY  24 * 60 * 60
#define BROADCAST_KEY "broadcast key".encode("ascii")
/* Length of a batch (2 hours) */
#define SECONDS_PER_BATCH  2 * 60 * 60
