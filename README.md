# Priority Layer System UI - Unreal Engine 5.4.4

## Description:

The Panel Layering Override System is a hierarchical UI widget management system designed for game environments that allows for flexible definition and control of user interfaces through a layered structure with a priority mechanism.

## Usage:

-> Different UI variants for various game modes.

-> Ability to quickly override interface elements without modifying base code.

-> Dynamic switching between different interface styles.

-> Modular UI structure with functionality inheritance.

## Settings in DataAsset

### Panel Definitions

Panel Overrides - the main key is a unique ID.

Name Panel - the name of the panel.

Layer Widget - we add a widget that must inherit from `UUserWidget`.

### Implementation

LayerManager - manages the hierarchy and priorities of layers.

PanelDefinition - defines a set of widgets for a given layer.

WidgetSpawner - responsible for creating and displaying appropriate widgets considering priorities.
