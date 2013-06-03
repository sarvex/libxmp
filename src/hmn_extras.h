#ifndef XMP_HMN_EXTRAS_H
#define XMP_HMN_EXTRAS_H

#define HMN_EXTRAS_MAGIC 0x041bc81a

struct hmn_instrument_extras {
	uint32 magic;
	int dataloopstart;
	int dataloopend;
	uint8 data[64];
	uint8 progvolume[64];
};

struct hmn_channel_extras {
	uint32 magic;
	int datapos;		/* HMN waveform table pointer */
	int volume;		/* HMN synth volume */
};
 
#define HMN_INSTRUMENT_EXTRAS(x) ((struct hmn_instrument_extras *)(x).extra)
#define HAS_HMN_INSTRUMENT_EXTRAS(x) \
	(HMN_INSTRUMENT_EXTRAS(x) != NULL && \
	 HMN_INSTRUMENT_EXTRAS(x)->magic == HMN_EXTRAS_MAGIC)

#define HMN_CHANNEL_EXTRAS(x) ((struct hmn_channel_extras *)(x).extra)
#define HAS_HMN_CHANNEL_EXTRAS(x) \
	(HMN_CHANNEL_EXTRAS(x) != NULL && \
	 HMN_CHANNEL_EXTRAS(x)->magic == HMN_EXTRAS_MAGIC)

void hmn_play_extras(struct context_data *, int, struct channel_data *, int);
void hmn_set_arpeggio(struct channel_data *, int);
int hmn_new_instrument_extras(struct xmp_instrument *);
int hmn_new_channel_extras(struct xmp_instrument *);

#endif
