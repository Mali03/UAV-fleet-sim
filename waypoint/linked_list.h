#ifndef WAYPOINT_LINKED_LIST_H
#define WAYPOINT_LINKED_LIST_H

#include "waypoint.h"

WaypointNode *wllCreateNode(Waypoint *waypoint);
WaypointNode *wllAddHead(WaypointNode *head, Waypoint *waypoint);
WaypointNode *wllAddTail(WaypointNode *head, Waypoint *waypoint);
void wllPrintList(WaypointNode *head);
int wllCount(WaypointNode *head);
WaypointNode *wllRemoveHead(WaypointNode *head);
WaypointNode *wllRemoveTail(WaypointNode *head);
WaypointNode *wllRemoveById(WaypointNode *head, int id);

#endif