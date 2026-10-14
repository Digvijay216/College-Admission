
#ifndef CUTOFFS_H
#define CUTOFFS_H

typedef struct {
    const char *branch;
    const char *exam;
    const char *category;
    double cutoff;
} Cutoff;

/*
    IMPORTANT:
    The MHT-CET cutoffs below are illustrative demo values.

    The four JEE Main values previously supplied are kept here
    as reference values, but must be verified against official
    year-, round-, seat-type- and category-specific data before
    being used for real admission decisions.

    Other JEE Main branch cutoffs are demo values only.
*/

static const Cutoff cutoffs[] = {

    /* ========== MHT-CET: SAMPLE VALUES ========== */

    {"Computer Science and Engineering (Aided)", "MHT-CET", "OPEN", 99.10},
    {"Computer Science and Engineering (Aided)", "MHT-CET", "OBC", 98.50},
    {"Computer Science and Engineering (Aided)", "MHT-CET", "SC", 95.00},
    {"Computer Science and Engineering (Aided)", "MHT-CET", "ST", 90.00},
    {"Computer Science and Engineering (Aided)", "MHT-CET", "EWS", 98.70},

    {"Computer Science and Engineering (Unaided)", "MHT-CET", "OPEN", 98.80},
    {"Computer Science and Engineering (Unaided)", "MHT-CET", "OBC", 97.90},
    {"Computer Science and Engineering (Unaided)", "MHT-CET", "SC", 93.50},
    {"Computer Science and Engineering (Unaided)", "MHT-CET", "ST", 87.00},
    {"Computer Science and Engineering (Unaided)", "MHT-CET", "EWS", 98.10},

    {"Information Technology (Aided)", "MHT-CET", "OPEN", 98.40},
    {"Information Technology (Aided)", "MHT-CET", "OBC", 97.50},
    {"Information Technology (Aided)", "MHT-CET", "SC", 92.00},
    {"Information Technology (Aided)", "MHT-CET", "ST", 85.00},
    {"Information Technology (Aided)", "MHT-CET", "EWS", 97.80},

    {"Information Technology (Unaided)", "MHT-CET", "OPEN", 98.00},
    {"Information Technology (Unaided)", "MHT-CET", "OBC", 97.00},
    {"Information Technology (Unaided)", "MHT-CET", "SC", 90.00},
    {"Information Technology (Unaided)", "MHT-CET", "ST", 82.00},
    {"Information Technology (Unaided)", "MHT-CET", "EWS", 97.30},

    {"Electronics Engineering", "MHT-CET", "OPEN", 96.50},
    {"Electronics Engineering", "MHT-CET", "OBC", 95.00},
    {"Electronics Engineering", "MHT-CET", "SC", 87.00},
    {"Electronics Engineering", "MHT-CET", "ST", 76.00},
    {"Electronics Engineering", "MHT-CET", "EWS", 95.50},

    {"Electrical Engineering", "MHT-CET", "OPEN", 94.00},
    {"Electrical Engineering", "MHT-CET", "OBC", 91.50},
    {"Electrical Engineering", "MHT-CET", "SC", 80.00},
    {"Electrical Engineering", "MHT-CET", "ST", 68.00},
    {"Electrical Engineering", "MHT-CET", "EWS", 92.00},

    {"Mechanical Engineering", "MHT-CET", "OPEN", 92.00},
    {"Mechanical Engineering", "MHT-CET", "OBC", 89.00},
    {"Mechanical Engineering", "MHT-CET", "SC", 75.00},
    {"Mechanical Engineering", "MHT-CET", "ST", 60.00},
    {"Mechanical Engineering", "MHT-CET", "EWS", 90.00},

    {"Civil Engineering", "MHT-CET", "OPEN", 88.00},
    {"Civil Engineering", "MHT-CET", "OBC", 84.00},
    {"Civil Engineering", "MHT-CET", "SC", 68.00},
    {"Civil Engineering", "MHT-CET", "ST", 52.00},
    {"Civil Engineering", "MHT-CET", "EWS", 85.00},

    {"Artificial Intelligence and Machine Learning", "MHT-CET", "OPEN", 98.60},
    {"Artificial Intelligence and Machine Learning", "MHT-CET", "OBC", 97.80},
    {"Artificial Intelligence and Machine Learning", "MHT-CET", "SC", 92.50},
    {"Artificial Intelligence and Machine Learning", "MHT-CET", "ST", 84.00},
    {"Artificial Intelligence and Machine Learning", "MHT-CET", "EWS", 98.00},

    {"Robotics and Automation", "MHT-CET", "OPEN", 95.00},
    {"Robotics and Automation", "MHT-CET", "OBC", 92.50},
    {"Robotics and Automation", "MHT-CET", "SC", 83.00},
    {"Robotics and Automation", "MHT-CET", "ST", 72.00},
    {"Robotics and Automation", "MHT-CET", "EWS", 93.50},


    /* ========== JEE MAIN: OPEN CATEGORY ========== */

    /* Reference values previously supplied; verify officially. */

    {"Computer Science and Engineering (Unaided)",
     "JEE Main(No categoryChoice)", "OPEN", 98.3252296},

    {"Information Technology (Unaided)",
     "JEE Main(No categoryChoice)", "OPEN", 97.8826415},

    {"Artificial Intelligence and Machine Learning",
     "JEE Main(No categoryChoice)", "OPEN", 97.8362536},

    {"Robotics and Automation",
     "JEE Main(No categoryChoice)", "OPEN", 96.7899800},


    /* Additional JEE Main branches: DEMO VALUES ONLY */

    {"Computer Science and Engineering (Aided)",
     "JEE Main(No categoryChoice)", "OPEN", 98.50},

    {"Information Technology (Aided)",
     "JEE Main(No categoryChoice)", "OPEN", 98.00},

    {"Electronics Engineering",
     "JEE Main(No categoryChoice)", "OPEN", 96.50},

    {"Electrical Engineering",
     "JEE Main(No categoryChoice)", "OPEN", 95.50},

    {"Mechanical Engineering",
     "JEE Main(No categoryChoice)", "OPEN", 94.00},

    {"Civil Engineering",
     "JEE Main(No categoryChoice)", "OPEN", 92.00}
};

#define CUTOFF_COUNT \
    ((int)(sizeof(cutoffs) / sizeof(cutoffs[0])))

#endif
