#ifndef WAYPOINT_H
#define WAYPOINT_H

typedef struct Waypoint {
    int id;
    float latitude;
    float longitude;
} Waypoint;

typedef struct WaypointNode {
    Waypoint *waypoint;
    struct WaypointNode *next;
} WaypointNode;

#endif